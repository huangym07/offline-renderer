#include <iostream>
#include <cstdio>
#include "paths.h"
#include "utils.h"

int main() {
#ifdef DEBUG
    std::cout << "Project root directory is " <<  PROJECT_ROOT_DIR << std::endl;
#endif
    
    int img_width = 784;
    int img_height = 784;

    freopen("image.ppm", "w", stdout);
    std::cout << "P3\n" << img_width << " " << img_height << "\n255\n";
    for (int j = 0; j < img_height; j++) {
        for (int i = 0; i < img_width; i++) {
            auto r = (double)i / (img_width - 1);
            auto g = (double)j / (img_height - 1);     
            auto b = 0.0;

            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << '\n';
        }
        UpdateProgress(1.0 * j / img_height);
    }
    UpdateProgress(1.0);
    std::clog << "Renderer complete: \n";
    fclose(stdout);
    freopen("/dev/tty", "w", stdout);

    return 0;
}
