#include "stdafx.h"
#include "IoEntity.h"

namespace Icarus
{
	IoEntity::IoEntity()
	{
		_initialized = false;
	}

	IoEntity::~IoEntity()
	{
		Close();

	}

	void IoEntity::Initialize()
	{
		if (_initialized)
			return;

		Init();
		_initialized = true;
	}

	void IoEntity::Close()
	{
		if (!_initialized)
			return;

		Clean();
		_initialized = false;
	}
}