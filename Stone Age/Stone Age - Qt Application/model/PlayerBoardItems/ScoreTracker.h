#ifndef SCORETRACKER_H
#define SCORETRACKER_H

class ScoreTracker {
    public:
        // Constructor
        ScoreTracker(int score);

        // Setters
        void increaseScore(int score);
        void decreaseScore(int score);
        void setScore(int score);

        // Getters
        int getScore() const;

    private:
        int m_score;
};

#endif // SCORETRACKER_H
