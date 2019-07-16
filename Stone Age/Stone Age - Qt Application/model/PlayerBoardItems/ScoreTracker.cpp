#include "ScoreTracker.h"


// Constructor
ScoreTracker::ScoreTracker(int score) : m_score{score} {}


// Setters
void ScoreTracker::increaseScore(int score) {
    m_score += score;
}
void ScoreTracker::decreaseScore(int score) {
    increaseScore(-score);
}

void ScoreTracker::setScore(int score) {
    m_score = score;
}


// Getters
int ScoreTracker::getScore() const {
    return m_score;
}
