//
// Created by Ivan Hromovyi on 31/08/2026.
//

#include "TMovieList.h"

#include <iostream>
#include <ostream>

TMovieList::TMovieList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

TMovieList::~TMovieList() {
    Clear();
}

int TMovieList::GetSize() {
    return size;
}

void TMovieList::Clear() {
    TMovieNode* cur = head;
    while (cur) {
        TMovieNode* nodeToDelete = cur;
        cur = cur->next;
        delete nodeToDelete;
    }
    head = nullptr;
    tail = head;
    size = 0;
}

void TMovieList::Append(TMovie *movie) {
    TMovieNode* newNode = new TMovieNode(movie);
    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void TMovieList::Prepend(TMovie *movie) {
    TMovieNode* newNode = new TMovieNode(movie);
    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

TMovie* TMovieList::GetAtIndex(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    TMovieNode* cur;
    int halfSize = size / 2;
    if (index < halfSize) {
        cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = tail;
        for (int i = size - 1; i > halfSize; i--) {
            cur = cur->prev;
        }
    }
    return cur->movie;
}

bool TMovieList::Remove(int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    TMovieNode* cur;
    if (index < size / 2) {
        cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = tail;
        for (int i = size - 1; i > index; i--) {
            cur = cur->prev;
        }
    }
    if (cur->prev == nullptr) {
        head = cur->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    } else if (cur->next == nullptr) {
        tail = cur->prev;
        tail->next = nullptr;
    } else {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    delete cur;
    size--;
    return true;
}

void TMovieList::Reverse() {
    TMovieNode* cur = head;
    while (cur != nullptr) {
        TMovieNode* temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;

        cur = temp;
    }

    TMovieNode* temp = tail;
    tail = head;
    head = temp;
}

void TMovieList::PrintAll() const {
    int index = 0;
    TMovieNode* cur = head;
    while (cur != nullptr) {
        std::cout << index++ << ". " << cur->movie->ToString() << std::endl;
        cur = cur->next;
    }
}

TMovie* TMovieList::SearchFor(FCheckMovie function, void* criteria) {
    TMovieNode* cur = head;
    while (cur != nullptr) {
        if (function(cur->movie, criteria)) {
            return cur->movie;
        }
        cur = cur->next;
    }
    return nullptr;
}

bool SearchByTitle(TMovie* movie, void* criteria) {
    const std::string* title = static_cast<const std::string*>(criteria);
    return movie->GetTitle() == *title;
}

bool SearchByDirector(TMovie* movie, void* criteria) {
    const std::string* director = static_cast<const std::string*>(criteria);
    return movie->GetDirector() == *director;
}

bool SearchByGenre(TMovie* movie, void* criteria) {
    const int* genre = static_cast<const int*>(criteria);
    return (movie->GetGenreFlags() & *genre) != 0;
}
