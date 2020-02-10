#pragma once

enum State {
    DISABLED,
    TESTING,
    AUTONOMOUS,
    TELEOP
};

static State c_robotState;

class Component {
   public:
    virtual void update() = 0;
    virtual void initialize() = 0;
    virtual void deinitialize() = 0;

    virtual bool updateCondition() {
        return true;
    }

    bool isInitialized() {
        return m_isInitialized;
    }

   protected:
    bool m_isInitialized = false;
};