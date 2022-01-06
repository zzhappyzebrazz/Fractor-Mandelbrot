#include "FractalCreator.h"

int programming::FractalCreator::getRange(int iterations) const
{
	int range = 0;
	for (int i = 1; i < m_ranges.size(); i++) {
		range = i;
		if (m_ranges[i] > iterations) {
			break;
		}
	}

	range--;
	assert(range > -1);
	assert(range < m_ranges.size());
	return range;
}

programming::FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height),
			m_histogram(new int[Mandelbrot::MAX_ITERATOR]{ 0 }), 
			m_fractal(new int[m_width * m_height]{ 0 }),
			m_bitmap(m_width, m_height),
			m_zoomlist(m_width, m_height)
{
	m_zoomlist.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

programming::FractalCreator::~FractalCreator()
{
}

void programming::FractalCreator::calculateIterator()
{
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++) {
			std::pair<double, double> coordinates = m_zoomlist.doZoom(x, y);

			int iterators = Mandelbrot::getIterators(coordinates.first, coordinates.second);
			m_fractal[y * m_width + x] = iterators;
			if (iterators != Mandelbrot::MAX_ITERATOR)
				m_histogram[iterators]++;

		}
}

void programming::FractalCreator::calculateTotalIt()
{
	for (int i = 0; i < Mandelbrot::MAX_ITERATOR; i++)
		m_total += m_histogram[i];

}

void programming::FractalCreator::drawFractal()
{
	//RGB startColor(0, 0, 0);
	//RGB endColor(0, 0, 255);
	//RGB colorDiff = endColor - startColor;
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++) {

			int iterators = m_fractal[y * m_width + x];
			int range = getRange(iterators);
			int rangeTotal = m_totalRanges[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range + 1];
			RGB colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			
			if (iterators != Mandelbrot::MAX_ITERATOR) {
				int totalPixels = 0;
				for (int i = rangeStart; i <= iterators; i++)
					totalPixels += m_histogram[i];

				//green = 255 * hue;// pow(255, hue);
				red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
				green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
				blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;
				
			}
			m_bitmap.setPixel(x, y, red, green, blue);
		}

}

void programming::FractalCreator::calculateRangeTotal()
{
	int rangeIndex = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATOR; i++) {
		int pixels = m_histogram[i];
		if (i >= m_ranges[rangeIndex + 1]) {
			rangeIndex++;
		}
		m_totalRanges[rangeIndex] += pixels;
	}
}

void programming::FractalCreator::addRanges(double rangeEnd, const RGB& rgb)
{
	m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATOR);
	m_colors.push_back(rgb);
	if (m_bGotFirstRange) {
		m_totalRanges.push_back(0);
	}

	m_bGotFirstRange = true;

}

void programming::FractalCreator::writeBitmap(std::string name)
{
	std::cout << std::endl;
	m_bitmap.write(name);
	std::cout << "Finish\n";
}

void programming::FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomlist.add(zoom);
}
