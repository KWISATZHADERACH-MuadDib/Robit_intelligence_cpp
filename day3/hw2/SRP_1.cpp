#include <iostream>
#include <string>

class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {
    }

    std::string getName() const {
        return name;
    }

    std::string getEmail() const {
        return email;
    }
};

class UserService {
public:
    void saveUser(const User& user) {   //유저의 정보를 저장하는 함수
        std::cout << "User saved to database: " << user.getName() << std::endl;
    }

    void sendWelcomeEmail(const User& user) {   //유저에게 환영 메세지를 전송하는 함수
        std::cout << "Welcome email sent to: " << user.getEmail() << std::endl;
    }

    void logUserActivity(const User& user) {    //유저의 로그를 기록하는 함수
        std::cout << "Logging activity for user: " << user.getName() << std::endl;
    }
};

int main() {
    User user("Hong Gildong", "hong@example.com");
    UserService service;

    service.saveUser(user);
    service.sendWelcomeEmail(user);
    service.logUserActivity(user);

    return 0;
}