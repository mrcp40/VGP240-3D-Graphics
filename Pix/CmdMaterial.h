#pragma once

#include "Command.h"

class CmdSetMaterialEmissive :public Command
{
public:
	const char* GetName()
	{
		return "SetMaterialEmissive";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialEmissive(r,g,b)\n"
			"\n"
			"- sets the rgb values for the material emissive color";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialAmbient :public Command
{
public:
	const char* GetName()
	{
		return "SetMaterialAmbient";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialAmbient(r,g,b)\n"
			"\n"
			"- sets the rgb values for the material Ambient color";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialDiffuse :public Command
{
public:
	const char* GetName()
	{
		return "SetMaterialDiffuse";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialDiffuse(r,g,b)\n"
			"\n"
			"- sets the rgb values for the material Diffuse color";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialSpecular :public Command
{
public:
	const char* GetName()
	{
		return "SetMaterialSpecular";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialSpecular(r,g,b)\n"
			"\n"
			"- sets the rgb values for the material Specular color";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialShininess :public Command
{
public:
	const char* GetName()
	{
		return "SetMaterialShininess";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialShininess(shininess)\n"
			"\n"
			"- sets the rgb values for the material shininess color";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

