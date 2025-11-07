#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <mutex>

class Logger {
private:
    static Logger* instance;
    std::ofstream fichier;
    std::mutex mtx;
    Logger();
public:
    static Logger* getInstance();
    void ecrire(const std::string& message);
};
#endif

#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <map>

class Config {
private:
    std::map<std::string, std::string> data;
public:
    bool charger(const std::string& chemin);
    std::string get(const std::string& cle) const;
};
#endif

#include "Logger.h"
Logger* Logger::instance = nullptr;
Logger::Logger() { fichier.open("journal.log", std::ios::app); }
Logger* Logger::getInstance() {
    static std::mutex guard;
    std::lock_guard<std::mutex> lock(guard);
    if (!instance) instance = new Logger();
    return instance;
}
void Logger::ecrire(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    fichier << message << std::endl;
}

#include "Config.h"
#include <fstream>
#include <sstream>
bool Config::charger(const std::string& chemin) {
    std::ifstream f(chemin);
    if (!f.is_open()) return false_
