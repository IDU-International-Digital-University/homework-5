#include <iostream>
#include <string>
using namespace std;

class Logger {
    public:
        virtual ~Logger() = default;
        virtual void log(const string& message) = 0;
};

class FileLogger : public Logger {
    public:
        void log(const string& message) override {
            cout << "[FILE] " << message << endl;
        }
};

class ConsoleLogger : public Logger {
    public:
        void log(const string& message) override {
            cout << "[CONSOLE] " << message << endl;
        }
};

class DatabaseLogger : public Logger {
    public:
        void log(const string& message) override {
            cout << "[DATABASE] " << message << endl;
        }
};

class LoggerFactory {
    public:
        static Logger* createLogger(const string& type) {
            if (type == "file") return new FileLogger();
            if (type == "console") return new ConsoleLogger();
            if (type == "database") return new DatabaseLogger();

            return nullptr;
        }
};

int ketmon() {
    Logger* logger = LoggerFactory::createLogger("console");
    if (!logger) {
        cout << "Invalid logger type!\n";
        return 0;
    }

    logger->log("System started");
    logger->log("Performing operation...");
    
    delete logger;
    return 0;
}
