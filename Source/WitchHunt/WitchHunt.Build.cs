// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WitchHunt : ModuleRules
{
	public WitchHunt(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
        PrivateDependencyModuleNames.AddRange(new string[] { "UMG", "GameplayTasks", "AIModule" });
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

    }
}
