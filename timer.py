import time

interval = 0
delay = 2
count = 0

while count <= 12:
    now = time.time()
    if now >= interval:
        print( str(count) + " seconds have passed.")
        interval = now + delay
        count += 2

    
