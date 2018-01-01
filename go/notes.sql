DROP DATABASE IF EXISTS posts;

CREATE DATABASE posts;

CREATE TABLE posts (
    id      SERIAL PRIMARY KEY,
    author  VARCHAR(255),
    link    TEXT,
    content TEXT,
    tag     TEXT []
);

COMMENT ON DATABASE posts IS 'Stored web page databse';

