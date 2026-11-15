#pragma once

namespace ProfileUtils {
    struct ChallengeStatusHolder {
        std::vector<std::wstring> challengeDesc;
        std::vector<bool>         challengeFailedState;
        std::vector<float>        numChallengeFailed;
        std::vector<bool>         challengeCompleteState;
        bool discovered;
        bool active;
        bool completed;
        bool completedThisPlay;
    };
}