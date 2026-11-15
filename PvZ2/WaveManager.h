#pragma once
#include <Sexy/RtObject.h>
#include <Sexy/RtWeakPtr.h>
#include <PvZ2/GameObject.h>
class WaveAction : public GameObject {
	RtWeakPtr<RtObject> m_propertySheetPtr;
};
class Wave {
	int Type;
	std::vector<RtWeakPtr<WaveAction>> Actions;
};
class WaveManager : public Sexy::RtObject
{
public:
	Sexy::RtWeakPtr<RtObject> m_props;
	std::vector<Wave> m_waves;
	int m_currentWave;
	float m_nextWaveTime;
	float m_lastWaveTime;
	int m_currentWaveTotalHealth;
	int m_nextWaveHealthThreshold;
	int m_state;
	bool m_paused;
	bool m_forceSpawnNextWave;
	bool m_hasDynamicZombies;
	char m_pad[5016];
};