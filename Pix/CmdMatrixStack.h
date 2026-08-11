#pragma once

#include "Command.h"

class CmdPushTranslation :public Command
{
public:
	const char* GetName() override
	{
		return "PushTranslation";
	}
	const char* GetDescription() override
	{
		return
			"PushTranslation(x,y,z)\n"
			"\n"
			"- pushes a translation matrix to the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPushRoationX :public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationX";
	}
	const char* GetDescription() override
	{
		return
			"PushRotationX(degrees)\n"
			"\n"
			"- pushes a rotation around the x axis matrix to the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPushRoationY :public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationY";
	}
	const char* GetDescription() override
	{
		return
			"PushRotationY(degrees)\n"
			"\n"
			"- pushes a rotation around the y axis matrix to the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPushRoationZ :public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationZ";
	}
	const char* GetDescription() override
	{
		return
			"PushRotationZ(degrees)\n"
			"\n"
			"- pushes a rotation around the z axis matrix to the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPushScaling :public Command
{
public:
	const char* GetName() override
	{
		return "PushScaling";
	}
	const char* GetDescription() override
	{
		return
			"PushScaling(x,y,z)\n"
			"\n"
			"- pushes a scale matrix to the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPopMatrix :public Command
{
public:
	const char* GetName() override
	{
		return "PopMatrix";
	}
	const char* GetDescription() override
	{
		return
			"PopMatrix()\n"
			"\n"
			"- pops the last matrix on the matrix stack";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
