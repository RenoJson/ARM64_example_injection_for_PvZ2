#pragma once
#include "GameObject.h"
#include "PropertySheetBase.h"
#include "TimeLine.h"
#include "WaveManager.h"

class LevelModuleProperties;
class Zombie;

class LevelModule : public GameObject
{
public:
	Sexy::RtWeakPtr<LevelModuleProperties> m_propertySheet;
};

static_assert(sizeof(LevelModule) == 24);
static_assert(offsetof(LevelModule, m_propertySheet) == 16);

class LevelModuleProperties : public PropertySheetBase
{
public:
	std::vector<SexyString> ResourceGroupNames;
	Sexy::RtWeakPtr<void> DifficultyProps;
	SexyString IconImage;
	SexyString IconText;
};

static_assert(sizeof(LevelModuleProperties) == 120);
static_assert(offsetof(LevelModuleProperties, ResourceGroupNames) == 40);
static_assert(offsetof(LevelModuleProperties, DifficultyProps) == 64);
static_assert(offsetof(LevelModuleProperties, IconText) == 96);

class WaveManagerModule : public LevelModule {
public:
	WaveManager m_waveManager;
	RT_CLASS_GET_CLASS_WRAPPER(0x8CF444);
};
class ZombiesAteYourBrainsModule : public LevelModule {
public:
	bool m_testingForZombieWin;
};

class OutroModule : public LevelModule {
public:
	RT_CLASS_GET_CLASS_WRAPPER(0x105F848);
};

class ZombiesAteYourBrainsOutro : public OutroModule {
public:
	RT_CLASS_GET_CLASS_WRAPPER(0x6567D8);
	Sexy::RtWeakPtr<Zombie> m_winningZombie;
	bool m_freezed = false;
	TimeLine m_outroTimeLine;
	int m_textToShow = 0;
};


class ZombiesAteYourBrainsProperties : public LevelModuleProperties {
public:
	char pad[4];
	float ZombieWinPositionX;
	bool ZombieDiesInsteadOfWinning;
};

class LawnMowerModule : public LevelModule {
public:
	std::vector<int> m_respawnsRemaining;
	std::vector<RtWeakPtr<void*>> m_purchaseButton; // LawnMowerPurchaseButton
};

class LawnMowerProperties : public LevelModuleProperties {
public:
	char pad[4];
	float MowerEntryAnimDuration;
	SexyString MowerPopAnim;
	SexyString MowerActivatedAudioEvent;
	std::vector<int> MowerIdleAnimWeight;
	int MowerExplodeAtGridX;
	bool UnlimitedMowers;
};

class Challenge : public LevelModule {
public:
	float m_failTime;
	int m_state;
};

class ChallengeModule : public LevelModule {
public:
	bool m_challengesWereCompleted;
};

class ChallengeModuleProperties : public LevelModuleProperties {
public:
	char pad[4];
	char pad1[4];
	std::vector<std::vector<RtWeakPtr<LevelModuleProperties>>> Challenges;
	std::vector<int> Difficulties;
};

