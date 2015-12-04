#pragma once

#include <exception>
#include <functional>
#include <map>
#include <string>

namespace FactoryExceptions {
    class TypeNotRegistered : public std::exception {
        public:
            TypeNotRegistered(std::string const& t)
                : std::exception()
                  , type{t}
            {
            }

            virtual ~TypeNotRegistered() = default;

            char const* what() const noexcept {
                return type.c_str();
            }

        private:
            std::string const type;
    };
}

/**
 * A Factory for creating objects which can be identified by strings.
 */
template <class BaseType>
class Factory {
    public:
        //typedef BaseType* CreateFunction();
        using CreateFunction = std::function<BaseType ()>;

        bool registerObject(std::string const& id, CreateFunction creator) {
            return this->types.emplace(id, creator).second;
        }

        BaseType* createObject(std::string const& id) const {
            auto it = this->types.find(id);

            if (it == this->types.end()) {
                throw FactoryExceptions::TypeNotRegistered{id};
            }

            return it->second();
        }

        std::map<std::string const, CreateFunction>& getTypes() {
            return this->types;
        }

    private:
        std::map<std::string const, CreateFunction> types;
};
