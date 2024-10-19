# EasyLoadingScreens
A FOSS plugin for Unreal Engine 5 to handle loading screens for your games!

## Usage
The following classes and methods are provided:

### `ULoadingScreenSubsystem`
Main class of the plugin, allows to create a loading widget to show as the loading screen, 
also provides a helper method to send messages to the created widget to update the loading status for the player.

### `ULoadingScreenUserWidget`
Parent class for your loading screen widget. Intercepts messages sent from the `ULoadingScreenSubsystem`.

### `ALoadingNotifier`
Utility class that automatically notifies the `ULoadingScreenSubsystem` when the level is ready.

> You can replace this actor with your own mechanism to determine when the loading screen should disappear.
> You just need to call either the `ULoadingScreenSubsystem::NotifyLevelLoadingFinished` or the `ULoadingScreenSubsystem::NotifyLevelLoadingError`.

## Usage example
![GM_MainMenu_EventGraph_00001](https://github.com/user-attachments/assets/4c251f66-54bc-46b8-8e99-dba8f8e1c609)

First, the loading screen widget is shown to the player using the `ShowLoadingScreen` method.
Then, the loading status is updated multiple times using the `SendLoadingMessage`. And finally,
the loading screen is closed using either the `NotifyLevelLoadingError` or the `NotifyLevelLoadingFinished` (not shown).

To simplify the setup, an utility actor is provided (`ALoadingNotifier`) that can be placed on any level and automatically notifies the
`ULoadingScreenSubsystem` that the level has finished loading.

# License
The license is provided in the `LICENSE.md` file, and is explained in the [official Creative Commons page](https://creativecommons.org/licenses/by-sa/4.0/).
