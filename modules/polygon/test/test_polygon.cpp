// Copyright 2021 Alibekov Murad

#include <gtest/gtest.h>

#include "include/polygon.h"

TEST(Alibekov_Murad_Polygon_Tests, Throw_If_Polygon_Without_Points) {
    // Arrange
    Points polygon = {};

    // Assert
    ASSERT_ANY_THROW(Polygon::PolygonArea(polygon));
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Point_Is_0) {
    // Arrange
    Points point = {{1, 1}};
    
    // Act
    double area = Polygon::PolygonArea(polygon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 0.);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Line_Is_0) {
    // Arrange
    Points line = {{0, 0}, {1, 2}};
    
    // Act
    double area = Polygon::PolygonArea(polygon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 0.);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Triangle) {
    // Arrange
    Points triangle = {{1.5, -0.5}, {1, 1}, {-1, 0.5}};
    
    // Act
    double area = Polygon::PolygonArea(polygon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 1.625);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Square) {
    // Arrange
    Points square = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    
    // Act
    double area = Polygon::PolygonArea(polygon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 1.);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Hexagon) {
    // Arrange
    Points hexagon = {{-2, 0}, {-1, 1}, {0.5, 1}, 
        {1.5, 0}, {0.5, -1}, {1, -1}};
    
    // Act
    double area = Polygon::PolygonArea(polygon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 5.);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Nonconvex_Pentagon) {
    // Arrange
    Points nonconvex_pentagon = {{3, 4}, {5, 11}, {12, 8}, {9, 5}, {5, 6}};
    
    // Act
    double area = Polygon::PolygonArea(nonconvex_pentagon);
    
    // Assert
    ASSERT_DOUBLE_EQ(area, 30.);
}
