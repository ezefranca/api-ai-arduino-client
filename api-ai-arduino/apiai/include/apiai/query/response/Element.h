#ifndef AIELEMENT_H
#define AIELEMENT_H

#include <map>
#include <string>
#include <memory>
#include <vector>

namespace ai{
    namespace query {
        namespace response {
            class Element {
            public:
                virtual bool isObject() const;
                virtual bool isNumber() const;
                virtual bool isArray() const;
                virtual bool isBool() const;
                virtual bool isString() const;

                virtual std::map<std::string, std::shared_ptr<Element>> asObject() const;
                virtual double asDouble() const;
                virtual int asInteger() const;
                virtual std::vector<std::shared_ptr<Element>> asArray() const;
                virtual bool asBool() const;
                virtual std::string asString() const;

                friend std::ostream& operator << (std::ostream& os, const Element& element);
            };

            std::ostream& operator << (std::ostream& os, const Element& element);

            template <typename T>
            class ValueContainer {
            public:
                ValueContainer(T value):value(value) {}

                T getValue() const
                {
                    return value;
                }
            private:
                T value;
            };

            class ObjectElement: private ValueContainer<std::map<std::string, std::shared_ptr<Element>>>, public Element{
            public:
                ObjectElement(std::map<std::string, std::shared_ptr<Element>> value);

                virtual bool isObject() const override;
                virtual std::map<std::string, std::shared_ptr<Element>> asObject() const override;
            };

            class ArrayElement: private ValueContainer<std::vector<std::shared_ptr<Element>>>, public Element {
            public:
                ArrayElement(std::vector<std::shared_ptr<Element>> value);

                virtual bool isArray() const override;
                virtual std::vector<std::shared_ptr<Element>> asArray() const override;
            };

            class StringElement: private ValueContainer<std::string>, public Element {
            public:
                StringElement(std::string value);

                virtual bool isString() const override;
                virtual std::string asString() const override;
            };

            class NumberElement: private ValueContainer<double>, public Element {
            public:
                NumberElement(double value);

                virtual bool isNumber() const override;
                virtual double asDouble() const override;
                virtual int asInteger() const override;
            };

            class BoolElement: private ValueContainer<bool>, public Element {
            public:
                BoolElement(bool value);

                virtual bool isBool() const override;
                virtual bool asBool() const override;
            };
        }
    }
}

#endif // AIELEMENT_H
