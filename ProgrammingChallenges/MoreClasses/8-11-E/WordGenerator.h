//
//  WordGenerator.h
//  PaperWriter
//
//  Created by Jayson Fong on 2/28/21.
//

#ifndef WordGenerator_h
#define WordGenerator_h

#include "WordType.h"

class WordGenerator {
  
private:
    
    static const int MAX_ENTITY_CHARS = 8;
    static const int MAX_ENTITIES = 5;
    
    static std::shared_ptr<char> getArticles() {
        static std::shared_ptr<char> articles(new char[MAX_ENTITIES * MAX_ENTITY_CHARS]);
        
        if (*articles.get() != '\0') {
            return articles;
        }
        
        const char tempArticles[MAX_ENTITIES][MAX_ENTITY_CHARS] = {
            "the", "a", "one", "some", "any"
        };
        
        for (int wordIndex = 0; wordIndex < MAX_ENTITIES; wordIndex++) {
            for (int charIndex = 0; charIndex < MAX_ENTITY_CHARS; charIndex++) {
                *(articles.get() + (wordIndex * MAX_ENTITY_CHARS) + charIndex) = tempArticles[wordIndex][charIndex];
            }
        }
        
        return articles;
    }

    static std::shared_ptr<char> getNouns() {
        static std::shared_ptr<char> nouns(new char[MAX_ENTITIES * MAX_ENTITY_CHARS]);
        
        if (*nouns.get() != '\0') {
            return nouns;
        }
        
        const char tempNouns[MAX_ENTITIES][MAX_ENTITY_CHARS] = {
            "boy", "girl", "dog", "town", "car"
        };
        
        for (int wordIndex = 0; wordIndex < MAX_ENTITIES; wordIndex++) {
            for (int charIndex = 0; charIndex < MAX_ENTITY_CHARS; charIndex++) {
                *(nouns.get() + (wordIndex * MAX_ENTITY_CHARS) + charIndex) = tempNouns[wordIndex][charIndex];
            }
        }
        
        return nouns;
    }

    static std::shared_ptr<char> getVerbs() {
        static std::shared_ptr<char> verbs(new char[MAX_ENTITIES * MAX_ENTITY_CHARS]);

        if (*verbs.get() != '\0') {
            return verbs;
        }
        
        const char tempVerbs[MAX_ENTITIES][MAX_ENTITY_CHARS] = {
            "drove", "jumped", "ran", "walked", "skipped"
        };
        
        for (int wordIndex = 0; wordIndex < MAX_ENTITIES; wordIndex++) {
            for (int charIndex = 0; charIndex < MAX_ENTITY_CHARS; charIndex++) {
                *(verbs.get() + (wordIndex * MAX_ENTITY_CHARS) + charIndex) = tempVerbs[wordIndex][charIndex];
            }
        }
        
        return verbs;
    }

    static std::shared_ptr<char> getPrepositions() {
        static std::shared_ptr<char> prepositions(new char[MAX_ENTITIES * MAX_ENTITY_CHARS]);
        
        if (*prepositions.get() != '\0') {
            return prepositions;
        }
        
        const char tempPrepositions[MAX_ENTITIES][MAX_ENTITY_CHARS] = {
            "to", "from", "over", "under", "on"
        };
        
        for (int wordIndex = 0; wordIndex < MAX_ENTITIES; wordIndex++) {
            for (int charIndex = 0; charIndex < MAX_ENTITY_CHARS; charIndex++) {
                *(prepositions.get() + (wordIndex * MAX_ENTITY_CHARS) + charIndex) = tempPrepositions[wordIndex][charIndex];
            }
        }
        
        return prepositions;
    }
    
    static char* getRandomEntity(std::shared_ptr<char> (*entityGenerator)()) {
        const int selectionIndex = rand() % MAX_ENTITIES;

        std::shared_ptr<char> entityPtr = entityGenerator();
        
        // Does not need to be a shared_ptr because it is static in the generator.
        return entityPtr.get() + (selectionIndex * MAX_ENTITY_CHARS);
    }
    
public:
    
    static char* getRandomByType(WordType wordType) {
        switch (wordType) {
            case WordType::ARTICLE:
                return getRandomEntity(&getArticles);
            case WordType::NOUN:
                return getRandomEntity(&getNouns);
            case WordType::VERB:
                return getRandomEntity(&getVerbs);
            case WordType::PREPOSITION:
            default:
                return getRandomEntity(&getPrepositions);
        }
    }
    
    static char* getRandomPunctuation() {
        int selectionIndex = rand() % 2;
        
        static char punctuation[2][2] = {
            ".", "!"
        };
        
        switch (selectionIndex) {
            case 0: return punctuation[0];
            default: case 1: return punctuation[1];
        }
    }
    
};

#endif /* WordGenerator_h */
