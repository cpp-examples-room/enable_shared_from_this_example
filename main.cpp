#include <memory>
#include <vector>
#include <iostream>

class Foo final: public std::enable_shared_from_this<Foo> {
    std::vector<std::shared_ptr<Foo>> objects_;
public:
    Foo() noexcept {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    ~Foo() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << objects_.size() << std::endl;
    }

    void process() {
        objects_.emplace_back(shared_from_this());
        std::cout << objects_.size() << std::endl;
    }

    void clear() {
        objects_.clear();
    }
};

int main() {
    auto foo = std::make_shared<Foo>();

    foo->process();
    foo->process();
    foo->process();

    foo->clear();
}
