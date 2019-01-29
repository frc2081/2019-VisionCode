#include "stdafx.h"
#include "IoEntity.h"

namespace Icarus
{
	void IoEntity::AssertInitialized()
	{
		if (!IsInitialized())
			throw "IO Entity is not initialized.";
	}

	IoEntity::IoEntity()
	{
		_initialized = false;
	}

	IoEntity::~IoEntity()
	{
		Close();
	}

	bool IoEntity::IsInitialized()
	{
		return _initialized;
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