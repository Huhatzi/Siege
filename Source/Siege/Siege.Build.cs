// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Siege : ModuleRules
{
	public Siege(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","AIModule"});

	}
}
