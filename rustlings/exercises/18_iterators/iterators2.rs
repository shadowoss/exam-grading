// to_uppercase函数：返回字符串的大写字母
// collect函数：将一个集合的内容移动到另一个集合的主要方式
// as_str() 可以显式提取包含该字符串的字符串片段
// next函数会让迭代器指向下一个对象
pub fn capitalize_first(input: &str) -> String {
    let mut c = input.chars();
    match c.next() {
        None => String::new(),
        Some(first) => first.to_uppercase().collect::<String>() + c.as_str(),
    }
}

// 改变vector中第一个字母为大写字母
pub fn capitalize_words_vector(words: &[&str]) -> Vec<String> {
    let mut col = vec![];
    for word in words
    {
        col.push(capitalize_first(word));
    }
    col 
}

//.join(" ") 将多维数组降维成中间为空格的一维数组
pub fn capitalize_words_string(words: &[&str]) -> String {
    let mut buffer = vec![];
    for word in words {
        buffer.push(capitalize_first(word));
        //println!("{:?}", buffer);
    }

    buffer.join("")
}


fn main() {
    // You can optionally experiment here.
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_success() {
        assert_eq!(capitalize_first("hello"), "Hello");
    }

    #[test]
    fn test_empty() {
        assert_eq!(capitalize_first(""), "");
    }

    #[test]
    fn test_iterate_string_vec() {
        let words = vec!["hello", "world"];
        assert_eq!(capitalize_words_vector(&words), ["Hello", "World"]);
    }

    #[test]
    fn test_iterate_into_string() {
        let words = vec!["hello", " ", "world"];
        assert_eq!(capitalize_words_string(&words), "Hello World");
    }
}
