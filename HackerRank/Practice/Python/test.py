import re

s = "hello, world! abc@example.com blah blah blah x.y.z@example.com hello, prayag! i_j_k@example.com blah blah blah r-s-t@example.com"

emails = re.findall(r"[\w+\.\-]+@[\w\.\-]+", s)
for email in emails:
    print(email)
