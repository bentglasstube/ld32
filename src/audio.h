#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>
#include <map>

#define FADE_TIME 500

class Audio {

  public:

    Audio();
    ~Audio();

    void play_sample(std::string name);
    void sfx_volume(int volume) { Mix_Volume(-1, MIX_MAX_VOLUME * volume / 10); }

    void pause() { Mix_Pause(-1); }
    void resume() { Mix_Resume(-1); }

    void play_music(std::string name);
    void stop_music() { Mix_FadeOutMusic(FADE_TIME); }
    void music_volume(int volume) { Mix_VolumeMusic(MIX_MAX_VOLUME * volume / 10); }

  private:

    Mix_Chunk* load_chunk(std::string file);
    Mix_Music* load_music(std::string file);

    typedef std::map<std::string, Mix_Chunk*> ChunkMap;
    typedef std::map<std::string, Mix_Music*> MusicMap;

    ChunkMap chunks;
    MusicMap musics;

};
