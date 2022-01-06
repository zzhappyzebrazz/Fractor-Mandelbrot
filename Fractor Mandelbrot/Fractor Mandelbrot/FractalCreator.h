#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

namespace programming {
	class FractalCreator {
	private:
		int m_width;
		int m_height;
		int m_total{ 0 };
		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal; 
		std::vector<int> m_ranges;
		std::vector<RGB> m_colors;
		Bitmap m_bitmap;
		ZoomList m_zoomlist;
		std::vector<int> m_totalRanges;
		bool m_bGotFirstRange{ false };

		int getRange(int iterations) const;

	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		
		void calculateIterator();
		void calculateTotalIt();
		void drawFractal();
		void calculateRangeTotal();
		void addRanges(double rangeEnd, const RGB& rgb);
		void writeBitmap(std::string name);
		void addZoom(const Zoom& zoom);
	};


}