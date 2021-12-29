#ifndef OPTIONS_MANAGER_H
#define OPTIONS_MANAGER_H

#include <fstream>
#include <json/json.h>
#include <string>
#include <sys/stat.h>

#ifdef __vita__
#include <psp2/io/stat.h>
#define mkdir(x, y) sceIoMkdir(x, y)
#endif

class OptionsManager {
public:
  void loadResources();

  void setHighscoreTimetrial(int score);
  void setHighscoreEndless(int score);
  void setMusicEnabled(bool value);
  void setSoundEnabled(bool value);
  void setFullscreenEnabled(bool value);

  int getHighscoreTimetrial();
  int getHighscoreEndless();
  bool getMusicEnabled();
  bool getSoundEnabled();
  bool getFullscreenEnabled();

private:
  const std::string optionsFile = "options.json";

  Json::Value options;

  void writeOptions();
  void loadOptions();

  std::string getOptionsDir();
};

#endif