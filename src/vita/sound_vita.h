
#ifndef __SOUND_VITA_H__
#define __SOUND_VITA_H__

#define FSOUND_FREE 1
#define NUMSFX (45)

typedef struct FSOUND_SAMPLE
{
	uint8_t* data;
	uint32_t size;
	uint32_t format;
	bool used;
	bool loop;
} FSOUND_SAMPLE;


typedef FSOUND_SAMPLE FMUSIC_MODULE;

void soundInit();
void soundClose();

int FSOUND_Init(uint32_t freq, uint32_t bpd, uint32_t unkn);

int FSOUND_GetSFXMasterVolume(); //
int FMUSIC_GetMasterVolume(FMUSIC_MODULE* s); 


void FMUSIC_SetMasterVolume(FMUSIC_MODULE* s, uint8_t volume);
void FMUSIC_FreeSong(FMUSIC_MODULE* s);
void FSOUND_SetSFXMasterVolume(uint8_t volson);

void initSFX(FSOUND_SAMPLE* s);
void loadSFX(FSOUND_SAMPLE* s, const char* filename, uint32_t format);

void FSOUND_PlaySound(int chl,FSOUND_SAMPLE* s);
void FMUSIC_StopSong(FMUSIC_MODULE* s);
void FMUSIC_SetLooping(FMUSIC_MODULE* s, bool flag);
void FMUSIC_PlaySong(FMUSIC_MODULE* s);

FSOUND_SAMPLE* FSOUND_Sample_Load(int flag, const char * f,int a, int b, int c);
FMUSIC_MODULE* FMUSIC_LoadSong(const char * f);

void FSOUND_Sample_Free(FSOUND_SAMPLE* s);

void FSOUND_Close();


#endif