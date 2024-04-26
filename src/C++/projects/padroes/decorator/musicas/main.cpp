#include "src/Music/Music.hpp"
#include "src/ConcMusic/ConcMusic.hpp"
#include "src/Decorators/Eco/Eco.hpp"
#include "src/Decorators/Equalizer/Equalizer.hpp"
#include "src/Decorators/Reverb/Reverb.hpp"

int main() {
    Music *music = new ConcMusic();
    music = new Eco(music);
    music = new Reverb(new Equalizer(music));

    music->play("Ela mora no meu peito");
}