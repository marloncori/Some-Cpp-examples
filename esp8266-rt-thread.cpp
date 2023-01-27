void wifi_init() {
    gpio_iof_config(GPIOB, IOF_UART_MASK);
    uart_init(UART1, 115200);
}
INIT_BOARD_EXPORT(wifi_init);

void wifi_cmd(char *cmd, int wait_time) {
    send_str(cmd);
    rt_thread_mdelay(wait_time);
}

int cmd(int argc, char **argv) {
    if(argc != 2) {
        rt_kprintf("USE: %s \n", argv[0]);
        return RT_ERROR;
    }
    wifi_cmd(argv[1], 0);
    return RT_EOK;
}
MSH_CMD_EXPORT(cmd, send wifi cmd.)

void recv_thread_entry(void *parameter) {
    int i = 0;
    char ch;
    while (1) {
        ch = wifi_read(UART1);
        if (ch == '\r' || ch == '\n') {
            recv_buff[i] = '\0';
            if (rt_strlen(recv_buff) > 0) {
                i = 0;
                rt_kprintf("%s\n", recv_buff);
            }
        }
        else {
            recv_buff[i] = ch;
            i++;
        }
    }
}

int wifi_thread_init(void) {
    rt_kprintf("wifi_thread_init\n");
    rt_err_t ret = RT_EOK;
    rt_thread_t tid = &recv_thread;
    ret = rt_thread_init(&recv_thread,
                        "receive_thread",
                        recv_thread_entry, RT_NULL,
                        &recv_thread_stack[0], sizeof(recv_thread_stack),
                        RECV_THREAD_PRIORITY, 10);
    if (tid != RT_NULL && ret == RT_EOK) 
        rt_thread_startup(tid);
    return RT_EOK;
}
INIT_APP_EXPORT(wifi_thread_init);