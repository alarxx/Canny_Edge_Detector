import cv2
import time

if __name__ == "__main__":
    start = time.perf_counter_ns()

    # OpenCV Canny
    img = cv2.imread("./lenna.png", cv2.IMREAD_GRAYSCALE)

    edges = cv2.Canny(img, 90, 160)

    # cv2.imshow("Original", img)
    # cv2.imshow("Canny OpenCV", edges)
    # cv2.waitKey(0)

    end = time.perf_counter_ns()
    duration_ns = end - start
    print(f"opencv_canny: {duration_ns} ns")
