#pragma once

class TimeLine {
public:
	TimeLine& m_timeLine;
	float m_totalDt;
	float m_remainingDt;
	float m_lastStep;
	bool m_stoppedAtEvent;
};