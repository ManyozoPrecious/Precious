import skills from "../data/skills.js"
import SkillCard from "./SkillCard"

function Skills () {
    return(
        <section className="max-w-6x1 mx-auto px-6 py-24">
            <h2 className="text-5x1 font-black text-center mb-16">
                Skills
            </h2>
            <div className="grid md:grid-cols-2 lg:grid-cols-4 gap-6">
                {skills.map((skill) => (<SkillCard
                    key={skill.name}
                    name= {skill.name}
                    level= {skill.level}
                    />))}
            </div>
        </section>
    );
} 
export default Skills; 