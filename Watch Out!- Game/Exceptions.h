#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Baza proprie pentru excepții
class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& msg) : std::runtime_error(msg) {}
};

// Excepție pentru resurse (Imagini)
class ResourceException : public GameException {
public:
    explicit ResourceException(const std::string& resourcePath) 
        : GameException("Eroare critica: Nu s-a putut incarca resursa de la: " + resourcePath) {}
};

// Excepție pentru logica jocului
class GameplayException : public GameException {
public:
    explicit GameplayException(const std::string& msg) : GameException("Eroare Gameplay: " + msg) {}
};

#endif//EXCEPTIONS_H