//
//  strucs.cpp
//  MegaK
//
//  Created by Алексей Плотников on 29.10.2022.
//  Copyright © 2022 Алексей Плотников. All rights reserved.
//

#include "strucs.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

//картинка
sf::Sprite image(std::string img) {
    sf::Image sterka_image;
    sterka_image.loadFromFile(img);
    sf::Texture sterka_texture;
    sterka_texture.loadFromImage(sterka_image);
    sf::Sprite sterka;
    sterka.setTexture(sterka_texture);
    return sterka;
}
