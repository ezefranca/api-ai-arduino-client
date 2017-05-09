#include <apiai/query/request/Entity.h>
#include <apiai/exceptions/InvalidArgumentException.h>

using namespace std;
using namespace ai::query::request;

Entry::Entry(const std::string &value, const std::vector<std::string> &synonyms): value(value), synonyms({})
{
    if (value.size() == 0) {
        throw ai::InvalidArgumentException("Value cannot be empty.");
    }

    for(auto& synonim: synonyms) {
        this->addSynonym(synonim);
    }
}

Entry& Entry::addSynonym(const std::string &synonym)
{
    if (value.size() == 0) {
        throw ai::InvalidArgumentException("Synonym cannot be empty.");
    }

    this->synonyms.push_back(synonym);
    return *this;
}

const std::string &Entry::getValue() const
{
    return value;
}

const std::vector<std::string> &Entry::getSynonyms() const
{
    return synonyms;
}

Entry::~Entry(){}

// Entity

Entity::Entity(/*const std::string &id,*/ const std::string &name, const std::vector<Entry> &entries): /*id(id),*/ name(name), entries(entries)
{
    if(name.size() == 0) {
        throw ai::InvalidArgumentException("Name cannot ne empty.");
    }
}

Entity& Entity::addEntry(const Entry &entry)
{
    this->entries.push_back(entry);
    return *this;
}

const std::string &Entity::getName() const
{
    return name;
}

const std::vector<Entry> &Entity::getEntries() const
{
    return entries;
}

Entity::~Entity(){}
