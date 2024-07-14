# Mandelbrot fractal
# FB - 201003254
from PIL import Image

# drawing area
xa = -2.5
xb = 1.5
ya = -1.5
yb = 1.5

# max iterations allowed
maxIt = 80

# image size
imgx = 2000
imgy = 1300
im = Image.new("HSV", (imgx, imgy),(0,0,0))

for y in range(imgy):
	zy = y * (yb - ya) / (imgy - 1) + ya
	for x in range(imgx):
		zx = x * (xb - xa) / (imgx - 1) + xa
		z = zx + zy * 1j
		c = z
		for i in range(maxIt):
			if abs(z) > 2.0: break
			z = z * z + c
		im.putpixel((x, y), (i % 4 * 64,80, i % 16 * 16))

im.convert('RGB').save('output30.png', 'PNG')
