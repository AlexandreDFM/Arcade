
# Arcade Documentation

## Class Core::
Le Coeur du programme est initialisé dans le main. Il permet le chargement de la librairie graphique indiqué par l’utilisateur ainsi que le menu

```
namespace Arcade {
    class Core {
        public:
            //////////////////////// Constructor ////////////////////////
            Core();
            Core(std::string lib);
            Core(std::string lib, std::string game);
            ~Core();
            //////////////////////// Setter ////////////////////////
            void setGraphic(IDisplay *graphic);
            void setGame(IGame *game);
            void setMenu();
            void setChangeLib(EventType event);
            void setChangeGame(EventType event);
            //////////////////////// Functions ////////////////////////
            void loop();
            void MenuGetChange();
            void changeLib(std::string lib);
            void changeGame(std::string game);
        private:
            size_t _indexLib;
            size_t _indexGame;
            MenuInfo _menuInfo;
            IGame *game;
            IDisplay *graphic;
            DLLoader *gameDll;
            DLLoader *graphicDll;
            std::vector<std::string> _libs;
            std::vector<std::string> _games;
    };
}
```

# Implémentation de lib et de jeux

## Implémenter un jeu

Pour pouvoir implementer un jeux il y a besoin de un entrypoint ainsi que une fonction getType

Exemple:

```
    extern "C" {
        IGame *entryPoint()
        {
            return new Menu();
        }
        char *getType()
        {
            return (char *) "gameMenu";
        }
    }
```

### Lancement de jeux

- La librairie du jeu dois être placés dans ./lib/
- Lancer Arcade, le jeu sera disponible dans le menu


## Implémenter une librairie graphique

Pour pouvoir implementer un jeux il y a besoin de un entrypoint ainsi que une fonction getType

Exemple:

```
    extern "C" {
        IGame *entryPoint()
        {
            return new SDL2();
        }
        char *getType()
        {
            return (char *) "LibSDL2";
        }
    }
```

### Lancement d'une librairie graphique

- La librairie du jeu dois être placés dans ./lib/
- Lancer Arcade, la librairie graphique sera disponible dans le menu ou au lancement en selection ./arcade ./lib/NomDeLaLib




## Interface Partagé

Les Interfaces de ce projet ont été partagé avec les groupes suivants:

- gwenael.hubler@epitech.eu
- hugo.houbert@epitech.eu
- maxime.mallet@epitech.eu