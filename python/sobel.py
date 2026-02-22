import cv2
import numpy as np

# Read image in grayscale
img = cv2.imread("lenna.png", cv2.IMREAD_GRAYSCALE)

# Sobel derivatives
gx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
cv2.imshow("Sobel X", gx)
cv2.waitKey(0)

gy = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)
cv2.imshow("Sobel Y", gy)
cv2.waitKey(0)

# Gradient magnitude
mag = np.sqrt(gx**2 + gy**2)

# Normalize to 0–255 and convert to uint8
mag = np.uint8(255 * mag / np.max(mag))

cv2.imshow("Sobel", mag)
cv2.waitKey(0)
cv2.destroyAllWindows()
