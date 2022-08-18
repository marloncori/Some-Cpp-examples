#include <string.h>
#include <malloc.h>
#include "C:/Program Files (x86)/eSpeak/docs/speak_lib.h"

espeak_POSITION_TYPE position_type;
espeak_AUDIO_OUTPUT output;
char* path = NULL;
int bufLength = 1000, options = 0;
void* user_data;
t_espeak_callback *synthCallback;
espeak_PARAMETER param;

char Voice[] = "English";
char text[] = "This is a sample English sentence.";
unsigned int size, position = 0;
unsigned int end_position = 0, flags = espeakCHARS_AUTO;
unsigned int* unique_identifier;

//std::string cmd_line("C:\Program Files (x86)\eSpeak\command_line\espeak ");

int main(int argc, char* argv[]){
 output = AUDIO_OUTPUT_PLAYBACK;
 espeak_Initialize(output, bufLength, path, options);
 espeak_SetVoiceByName(Voice);
 const char* langNativeTag = "en";
 espeak_VOICE utterance = {0};

 utterance.languages = langNativeTag;
 utterance.name = "US";
 utterance.variant = 2;
 utterance.gender = 1;
 espeak_SetVoiceByProperties(&utterance);

 size = sizeof(text)+1;
 espeak_Synth(text, size, position, position_type, 
      end_position, flags, unique_identifier, user_data);
 espeak_Synchronize();

 return 0;
}
