//
//  PaperWriter.h
//  PaperWriter
//
//  Created by Jayson Fong on 2/28/21.
//

#ifndef PaperWriter_h
#define PaperWriter_h

#include <string>
#include <iostream>
#include <memory>
#include <cstring>
#include "GeneratorType.h"
#include "WordGenerator.h"
#include "WordType.h"

class PaperWriter {
  
private:
    
    GeneratorType generatorType;
    
    static const unsigned int PARAGRAPH_SENTENCES = 20;
    static const unsigned int THESIS_PARAGRAPHS = 5;
    
    int getSequenceLength(char** chars, const unsigned int ARR_LEN) {
        unsigned int totalChars = 0;
        for (int charIndex = 0; charIndex < ARR_LEN; charIndex++) {
            totalChars += std::strlen(chars[charIndex]);
        }
        return totalChars;
    }
    
    // Requires at least 3 elements, including punctuation.
    void combine(std::shared_ptr<char> sequence, char** chars, const unsigned int LENGTH, const unsigned int ARR_LEN) {
        strcpy(sequence.get(), chars[0]);
        for (int charIndex = 1; charIndex < ARR_LEN - 1; charIndex++) {
            strcat(sequence.get(), " ");
            strcat(sequence.get(), chars[charIndex]);
        }
        strcat(sequence.get(), chars[ARR_LEN - 1]);
        *sequence.get() = toupper(*sequence.get());
    }
    
    std::shared_ptr<char> getRandomSentence() {
        char* article = WordGenerator::getRandomByType(WordType::ARTICLE);
        char* articleTwo = WordGenerator::getRandomByType(WordType::ARTICLE);
        char* noun = WordGenerator::getRandomByType(WordType::NOUN);
        char* nounTwo = WordGenerator::getRandomByType(WordType::NOUN);
        char* verb = WordGenerator::getRandomByType(WordType::VERB);
        char* preposition = WordGenerator::getRandomByType(WordType::PREPOSITION);
        char* punctuation = WordGenerator::getRandomPunctuation();
        const unsigned int COUNT = 7;
        char* chars[COUNT] = {
            article, noun, verb, preposition, articleTwo, nounTwo, punctuation
        };
        const unsigned int TOTAL_LENGTH = getSequenceLength(chars, COUNT) + COUNT;
        
        static std::shared_ptr<char> sequence(new char[TOTAL_LENGTH]);
        combine(sequence, chars, TOTAL_LENGTH, COUNT);
        
        return sequence;
    }
    
    void generateParagraph() {
        for (unsigned int sentenceNumber = 0; sentenceNumber < PARAGRAPH_SENTENCES - 1; sentenceNumber++) {
            std::cout << getRandomSentence().get() << ' ';
        }
        std::cout << getRandomSentence().get() << std::endl;
    }
    
    void generateTermPaper() {
        for (unsigned int paragraphNumber = 0; paragraphNumber < THESIS_PARAGRAPHS; paragraphNumber++) {
            std::cout << '\t';
            generateParagraph();
        }
    }
    
    void process() {
        std::string divider(75, '=');
        
        std::cout << divider << std::endl;
        
        switch (generatorType) {
            case GeneratorType::PARAGRAPH:
            default:
                generateParagraph();
                break;
            case GeneratorType::TERM_PAPER:
                generateTermPaper();
                break;
        }
        
        std::cout << divider << std::endl;
    }
    
public:
    
    PaperWriter(GeneratorType genType) {
        generatorType = genType;
    }
    
    void run() {
        process();
    }
    
};

#endif /* PaperWriter_h */
