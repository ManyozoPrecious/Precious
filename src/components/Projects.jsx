import projects from "../data/projects";
import ProjectCard from "./ProjectCard";

function Projects() {
  return (
    <section className="max-w-6xl mx-auto px-6 py-24">

      <h2 className="text-5xl font-black text-center mb-4">
        Featured Projects
      </h2>

      <p className="text-center text-gray-400 max-w-2xl mx-auto mb-16">
        A collection of projects I've built while learning and growing as
        a software developer.
      </p>

      <div className="grid gap-8 md:grid-cols-2">

        {projects.map((project) => (
          <ProjectCard
            key={project.title}
            title={project.title}
            description={project.description}
            image={project.image}
            technologies={project.technologies}
            github={project.github}
            live={project.live}
          />
        ))}

      </div>

    </section>
  );
}

export default Projects;