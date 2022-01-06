#include "FractalCreator.h"

using namespace programming;

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	RGB rgb(3, 8, 9);
	FractalCreator fractalcreator(WIDTH, HEIGHT);

	fractalcreator.addRanges(0.0, RGB(0, 0, 255));
	fractalcreator.addRanges(0.05, RGB(255, 99, 71));
	fractalcreator.addRanges(0.08, RGB(255, 215, 0));
	fractalcreator.addRanges(1.0, RGB(255, 255, 255));

	fractalcreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
	fractalcreator.addZoom(Zoom(294, HEIGHT - 303, 0.1));
	fractalcreator.addZoom(Zoom(397, HEIGHT - 260, 0.1));
	fractalcreator.addZoom(Zoom(461, HEIGHT - 401, 0.1));

	fractalcreator.calculateIterator();
	fractalcreator.calculateRangeTotal();
	fractalcreator.calculateTotalIt();
	fractalcreator.drawFractal();
	
	fractalcreator.writeBitmap("image.bmp");

	std::cin.get();
	return 0;
}