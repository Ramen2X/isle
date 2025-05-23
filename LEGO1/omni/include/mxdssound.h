#ifndef MXDSSOUND_H
#define MXDSSOUND_H

#include "mxdsmediaaction.h"

// VTABLE: LEGO1 0x100dcdd0
// VTABLE: BETA10 0x101c2b68
// SIZE 0xc0
class MxDSSound : public MxDSMediaAction {
public:
	MxDSSound();
	MxDSSound(MxDSSound& p_dsSound);
	~MxDSSound() override;

	void CopyFrom(MxDSSound& p_dsSound);
	MxDSSound& operator=(MxDSSound& p_dsSound);

	// FUNCTION: LEGO1 0x100c9330
	// FUNCTION: BETA10 0x1015d950
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x101025e4
		return "MxDSSound";
	}

	// FUNCTION: LEGO1 0x100c9340
	// FUNCTION: BETA10 0x1015d970
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, MxDSSound::ClassName()) || MxDSMediaAction::IsA(p_name);
	}

	MxU32 GetSizeOnDisk() override;                              // vtable+0x18
	void Deserialize(MxU8*& p_source, MxS16 p_unk0x24) override; // vtable+0x1c
	MxDSAction* Clone() override;                                // vtable+0x2c

	// FUNCTION: BETA10 0x1008d060
	MxS32 GetVolume() const { return m_volume; }

	// SYNTHETIC: LEGO1 0x100c9450
	// SYNTHETIC: BETA10 0x1015d9d0
	// MxDSSound::`scalar deleting destructor'

private:
	MxU32 m_sizeOnDisk; // 0xb8
	MxS32 m_volume;     // 0xbc
};

#endif // MXDSSOUND_H
