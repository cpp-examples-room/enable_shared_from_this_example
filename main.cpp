#include <memory>
#include <vector>
#include <iostream>

class Foo final: public std::enable_shared_from_this<Foo> {
public:
    Foo() noexcept {
        std::cout << __func__ << std::endl;
    };

    ~Foo() {
        std::cout << __func__ << std::endl;
        std::cout << "size == " << objects_.size() << std::endl;
    }

    void process() {
        std::cout << __func__ << std::endl;
        objects_.emplace_back(shared_from_this());
        std::cout << "size == " << objects_.size() << std::endl;
    }

    void clear() {
        objects_.clear();
    }

private:
    std::vector<std::shared_ptr<Foo>> objects_;
};

int main() {
    auto foo = std::make_shared<Foo>();

    foo->process();
    foo->process();
    foo->process();

    foo->clear();
}
