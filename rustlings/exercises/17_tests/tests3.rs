struct Rectangle {
    width: i32,
    height: i32,
}

impl Rectangle {
    // Don't change this function.
    fn new(width: i32, height: i32) -> Self {
        if width <= 0 || height <= 0 {
            // Returning a `Result` would be better here. But we want to learn
            // how to test functions that can panic.
            panic!("Rectangle width and height must be positive");
        }

        Rectangle { width, height }
    }
}

fn main() {
    // You can optionally experiment here.
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn correct_width_and_height() {
        // 检查矩形的宽度和高度是否正确
        let rect = Rectangle::new(10, 20);
        assert_eq!(rect.width, 10); // 检查宽度
        assert_eq!(rect.height, 20); // 检查高度
    }

    // 检查程序在尝试创建具有负宽度的矩形时是否会引发恐慌
    #[test]
    #[should_panic(expected = "Rectangle width and height must be positive")]
    fn negative_width() {
        let _rect = Rectangle::new(-10, 10);
    }

    // 检查程序在尝试创建具有负高度的矩形时是否会引发恐慌
    #[test]
    #[should_panic(expected = "Rectangle width and height must be positive")]
    fn negative_height() {
        let _rect = Rectangle::new(10, -10);
    }
}

