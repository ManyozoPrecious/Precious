function ProjectCard({
    title,
    description,
    image,
    technologies,
    github,
    live,
  }) {
    return (
      <div className="rounded-3xl bg-white/5 backdrop-blur-md border border-white/10 overflow-hidden transition-all duration-300 hover:scale-[1.02] hover:border-cyan-400/40 hover:bg-white/10">
  
        <div className="h-56 overflow-hidden">
          <img
            src={image}
            alt={title}
            className="w-full h-full object-cover transition-transform duration-500 hover:scale-110"
          />
        </div>
  
        <div className="p-6">
  
          <h3 className="text-2xl font-bold mb-3">
            {title}
          </h3>
  
          <p className="text-gray-400 leading-7 mb-5">
            {description}
          </p>
  
          <div className="flex flex-wrap gap-2 mb-6">
            {technologies.map((tech) => (
              <span
                key={tech}
                className="px-3 py-1 rounded-full bg-cyan-500/10 border border-cyan-400/20 text-cyan-300 text-sm"
              >
                {tech}
              </span>
            ))}
          </div>
  
          <div className="flex gap-4">
  
            <a
              href={live}
              target="_blank"
              rel="noreferrer"
              className="rounded-xl bg-gradient-to-r from-blue-600 to-cyan-500 px-5 py-3 font-semibold transition-all duration-300 hover:scale-105 hover:shadow-lg hover:shadow-cyan-500/30"
            >
              Live Demo
            </a>
  
            <a
              href={github}
              target="_blank"
              rel="noreferrer"
              className="rounded-xl border border-white/20 px-5 py-3 transition-all duration-300 hover:border-cyan-400 hover:text-cyan-300"
            >
              GitHub
            </a>
  
          </div>
  
        </div>
      </div>
    );
  }
  
  export default ProjectCard;