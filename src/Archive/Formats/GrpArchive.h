
#ifndef __GRPARCHIVE_H__
#define __GRPARCHIVE_H__

#include "Archive/Archive.h"

class GrpArchive : public TreelessArchive
{
public:
	GrpArchive();
	~GrpArchive();

	// GRP specific
	uint32_t	getEntryOffset(ArchiveEntry* entry);
	void		setEntryOffset(ArchiveEntry* entry, uint32_t offset);

	// Opening/writing
	bool	open(MemChunk& mc) override;						// Open from MemChunk
	bool	write(MemChunk& mc, bool update = true) override;	// Write to MemChunk

	// Misc
	bool	loadEntryData(ArchiveEntry* entry) override;

	// Entry addition/removal
	ArchiveEntry*	addEntry(
						ArchiveEntry* entry,
						unsigned position = 0xFFFFFFFF,
						ArchiveTreeNode* dir = nullptr,
						bool copy = false
					) override;
	ArchiveEntry*	addEntry(ArchiveEntry* entry, string add_namespace, bool copy = false) override;

	// Entry modification
	bool	renameEntry(ArchiveEntry* entry, string name) override;

	// Static functions
	static bool isGrpArchive(MemChunk& mc);
	static bool isGrpArchive(string filename);
};

#endif//__GRPARCHIVE_H__
