//
// Created by Ivan Hromovyi on 31/08/2026.
//

#include "TMovieNode.h"

TMovieNode::TMovieNode(TMovie *movie)
    : movie(movie), next(nullptr), prev(nullptr) {
}

TMovieNode::~TMovieNode() {
    delete movie;
}
