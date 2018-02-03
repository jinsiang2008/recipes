# From tika, load from environ path or create temp one
TikaJarPath = os.getenv('TIKA_PATH', tempfile.gettempdir())
