function Contact() {
  return (
    <section
      className="max-w-4xl mx-auto px-6 py-24"
      data-aos="fade-up"
    >
      <div className="rounded-3xl bg-white/5 backdrop-blur-md border border-white/10 p-10 text-center">

        <h2 className="text-5xl font-black mb-6">
          Let's Build Something Together
        </h2>

        <p className="text-gray-400 leading-8 max-w-2xl mx-auto">
          I'm always open to internships, collaborations,
          freelance work, or simply connecting with other
          developers. Feel free to reach out!
        </p>

        <div className="mt-10 space-y-4">

          <p>
            📧
            <a
              href="mailto:preciousmanyozo12@gmail.com"
              className="ml-2 hover:text-cyan-400 transition-colors"
            >
              preciousmanyozo12@gmail.com
            </a>
          </p>

          <p>
            💼
            <a
              href="https://linkedin.com/in/YOUR_USERNAME"
              target="_blank"
              rel="noreferrer"
              className="ml-2 hover:text-cyan-400 transition-colors"
            >
              LinkedIn
            </a>
          </p>

          <p>
            🐙
            <a
              href="https://github.com/YOUR_USERNAME"
              target="_blank"
              rel="noreferrer"
              className="ml-2 hover:text-cyan-400 transition-colors"
            >
              GitHub
            </a>
          </p>

        </div>

        <a
          href="mailto:preciousmanyozo12@gmail.com"
          className="inline-block mt-10 rounded-xl bg-gradient-to-r from-blue-600 to-cyan-500 px-8 py-4 font-semibold transition-all duration-300 hover:scale-105 hover:shadow-lg hover:shadow-cyan-500/30"
        >
          Send Email
        </a>

      </div>
    </section>
  );
}

export default Contact;