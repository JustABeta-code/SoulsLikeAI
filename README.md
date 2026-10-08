# Squad Combat Encounter

Souls-like squad AI in Unreal Engine 5.8 using C++: modular and reactive behaviour systems. GOAP and Squad systems with collective and single priorities.

<!-- Hero GIF goes here once it exists -->
<!-- ![Squad encounter](Docs/Media/hero.gif) -->

**Status:** in development, week 1 of 4. Systems will be marked below as they land.

## Systems

| System | Status |
|---|---|
| Perception controller (sight, hearing, ... ) | In progress |
| Melee Behavior Tree (idle, patrol, combat, ... ) | Planned |
| Squad subsystem (attack tokens, roles, shared knowledge, ... ) | Planned |
| EQS spacing test | Planned |
| Archer covering position | Planned |
| Per-enemy and Squad GOAP planner | Planned |
| Gameplay Debugger & Visual Logger | Planned |

<!-- Architecture diagram goes here in week 4 -->

<!-- Copy this block for each finished system:

### Attack tokens
![Attack tokens](Docs/Media/tokens.gif)

One or two sentences on the problem it solves. One or two on how it works.
One sentence on the decision worth explaining (why tokens and not a cooldown, etc.).

Code: [SquadSubsystem.cpp](Source/SoulsLikeAI/...)
-->

## Tech

Unreal Engine 5.8 · C++ · Behavior Trees · EQS · AI Perception · Squad System · Gameplay Debugger · Visual Logger

## Contribution and credits

Solo project. All AI and combat code is mine. The player character is built on the Unreal Engine Third Person template; those files keep Epic's copyright header.

Art: <asset pack name and link>. Not included in this repository.

## Building

1. Clone the repository.
2. Get <asset pack name> and place it in `Content/Assets/<AssetPackFolder>/`.
3. Right-click `SoulsLikeAI.uproject` and choose Generate Visual Studio project files.
4. Build Development Editor | Win64 and open the project.

## Links

Breakdown: coming soon · Playable build: coming soon · Video: coming soon
