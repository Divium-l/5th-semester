#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "review.hpp"

void printReviewsByRating(std::vector<std::shared_ptr<Review>> vector);
void printReviewsAlphabatically(std::vector<std::shared_ptr<Review>> vector);
void printReviews(const std::vector<std::shared_ptr<Review>> &vector);

int main(int argc, char **argv) {
    auto reviews = std::vector<std::shared_ptr<Review>>();

    auto review_1 = std::shared_ptr<Review>(new Review(L"House of the Dragon", 50));
    auto review_2 = std::shared_ptr<Review>(new Review(L"LOTR TV Series", 30));
    auto review_3 = std::shared_ptr<Review>(new Review(L"Breaking Bad", 100));
    auto review_4 = std::shared_ptr<Review>(new Review(L"Halloween Kills", 25));

    reviews.push_back(review_1);
    reviews.push_back(review_2);
    reviews.push_back(review_3);
    reviews.push_back(review_4);

    std::cout << "Printing alphabetically: " << std::endl;
    printReviewsAlphabatically(reviews);
    std::cout << std::endl;

    std::cout << "Printing by rating: " << std::endl;
    printReviewsByRating(reviews);
    std::cout << std::endl;

    std::cout << "Reviews without any order: " << std::endl;
    printReviews(reviews);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

void printReviewsByRating(std::vector<std::shared_ptr<Review>> vector) {
    std::sort(vector.begin(), 
        vector.end(), 
        [](std::shared_ptr<Review> reviewPtr_1, std::shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getRating() > reviewPtr_2.get()->getRating();
    });
    
    printReviews(vector);
}

void printReviewsAlphabatically(std::vector<std::shared_ptr<Review>> vector) {
    std::sort(vector.begin(), 
        vector.end(), 
        [](std::shared_ptr<Review> reviewPtr_1, std::shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getText().compare(reviewPtr_2.get()->getText()) < 0;
    });
    
    printReviews(vector);
}

void printReviews(const std::vector<std::shared_ptr<Review>> &vector) {
    for (auto review : vector)
        std::wcout << review.get()->toString() << std::endl;
}
