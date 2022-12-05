import cv2
import numpy as np
import matplotlib.pyplot as plt
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

image = cv2.imread("input_image.jpeg", cv2.IMREAD_GRAYSCALE)
image_enhanced = cv2.equalizeHist(src=image)

cv2.imshow("Grayscale Image", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
print("image shape: " , image.shape)
print("pixels in grayscale image: ", image.shape[0] * image.shape[1])

plt.hist(x=image.ravel(), bins=256, range=[0, 256], color="crimson")
plt.title("Histogram Showing Pixel Intensities And Counts", color="crimson")
plt.ylabel("Number Of Pixels Belonging To The Pixel Intensity", color="crimson")
plt.xlabel("Pixel Intensity", color="crimson")
plt.show()


cv2.imshow("Enhanced Contrast Image", image_enhanced)
cv2.waitKey(0)
cv2.destroyAllWindows()

plt.hist(image_enhanced.ravel(), 256, [0, 256], color="blue")
plt.title("Pixel Intensities And Counts In Enhanced Image", color="crimson")
plt.ylabel("Number Of Pixels Belonging To Pixel Intensity", color="crimson")
plt.xlabel("Pixel Intensity", color="crimson")
plt.show()

if rank == 1:
    cv2.imshow("Grayscale Image", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    print(image.shape)
    print(
        "Total number of pixels in grayscale image: ", image.shape[0] * image.shape[1]
    )


elif rank == 2:

    plt.hist(x=image.ravel(), bins=256, range=[0, 256], color="crimson")
    plt.title("Histogram of Pixel Intensities And Counts", color="crimson")
    plt.ylabel("Number Of Pixels", color="crimson")
    plt.xlabel("Pixel Intensity", color="crimson")
    plt.show()


elif rank == 0:
    cv2.imshow("Enhanced Contrast Image", image_enhanced)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

elif rank == 3:
    plt.hist(image_enhanced.ravel(), 256, [0, 256], color="blue")
    plt.title("Histogram of Enhanced Image", color="crimson")
    plt.ylabel("Number Of Pixels", color="crimson")
    plt.xlabel("Pixel Intensity", color="crimson")
    plt.show()